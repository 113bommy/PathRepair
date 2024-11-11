n = int(input())
a=[1]
for i in range(1,n):
    a.append(1)
    while len(a)>1 and a[-1]==a[-2]:
        a=a[:-2]+[a[-1]+1]
for i in range(len(a)):
    print(a[i],"",end="")
    
