a,m = map(int,input().split())

for i in range(100000):
    if a%m==0:
        print("Yes")
        quit()
    else:
        a+=a%m
print("No")