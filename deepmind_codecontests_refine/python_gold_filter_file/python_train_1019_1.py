n=int(input())
s=input()
w=b=0
mn=0
for sk in s:
    if sk=="#":
        b+=1
    else:
        w-=1
    if mn>b+w:
        mn=b+w
print(mn-w)