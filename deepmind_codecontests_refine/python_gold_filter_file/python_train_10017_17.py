n = int(input())
a = list(map(int , input().split()))
if n==1:
    print(1)
    exit()
co = 0
ce = 0
for i in a:
    if i%2==0:
        ce+=1
    else: co+=1
if co==0 or co%2==0:
    print(ce)
elif co%2==1:
    print(co)
