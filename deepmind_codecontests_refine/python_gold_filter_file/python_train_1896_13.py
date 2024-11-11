n=int(input())
numere=input().split()
for i in numere:
    x=int(i)
    rest=x%14
    if((rest==1 or rest==2 or rest==3 or rest==4 or rest==5 or rest==6) and x>14):
        print("YES")
    else:
        print("NO")