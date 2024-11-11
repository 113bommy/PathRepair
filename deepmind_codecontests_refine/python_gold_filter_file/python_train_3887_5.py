n=int(input())
s=[int(x) for x in input().strip().split(" ")]
tot=sum(s)
i=0
pick=0
s.sort(reverse=True)
while i<len(s):
    x=s[i]
    pick=pick+x
    if (2*pick)>tot:
        break
    i=i+1
print(i+1)