a,m = map(int,input().split())

for i in range(17):
    if a%m==0:
        print("Yes")
        quit()
    else:
        a+=a%m
print("No")