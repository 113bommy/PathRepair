n = int(input())
A = [0] * n
per = 0
ans1 = float('infinity')
ans2 = -float('infinity')
for j in range(n):
    per1,per2 = map(int,input().split())
    if per2 == 1:
        if ans1 < 1900:
            per = 1
            break
        else:
            ans2 = max(ans2,1900)
            ans1 += per1
            ans2 += per1
    else:
        if ans2 >= 1900:
            per =1 
            break
        else:
            ans1 = min(ans1,1899)
            ans1 += per1
            ans2 += per1
   
    if ans1 < ans2:
        per = 1
        break
    
if per == 0:
    if ans1 == float('infinity'):
        print('Infinity')
    else:
        
        print(ans1)
else:
    print('Impossible')