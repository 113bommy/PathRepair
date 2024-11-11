n,k=list(map(int,input().split()))
ints=list(map(int,input().split()))
good=0
l=0
for num in ints:
    for char in str(num):
        if char=="4"or char=="7":
            l+=1
    if l<=k:
        good+=1
    l=0
print(good)
