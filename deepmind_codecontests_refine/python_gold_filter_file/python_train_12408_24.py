#1228a Distinct Digits 

l,r = map(int,input().split())
while l<=r:
    if len(str(l)) == len(set(str(l))):
        print(l)
        exit()
    l+=1
print(-1)
