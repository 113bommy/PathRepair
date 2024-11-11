raw=input()

raw=raw.split(" ")
raw=[int(x) for x in raw]
a=0
for x in raw:
    a=a+x
if a==0:
    print(-1)
elif a % 5 !=0:
    print(-1)
else:
    print(int(a/5))
