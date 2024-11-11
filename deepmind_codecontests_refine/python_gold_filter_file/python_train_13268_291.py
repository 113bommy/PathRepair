n = int(input())
a = 0
for i in range (n):
    p,c = map(int, input().split())
    if c-p>=2:
        a+=1
    else:
        pass
print(a)
    
