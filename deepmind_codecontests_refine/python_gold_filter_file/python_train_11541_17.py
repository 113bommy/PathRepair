a,b,c=map(int,input().split())
for i in range(1,b+1):
    if i*a%b==c:
        print("YES")
        exit()
print("NO")