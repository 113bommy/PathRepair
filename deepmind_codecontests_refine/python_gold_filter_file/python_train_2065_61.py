n=int(input())
ln=[int(a) for a in input().split()]
i=0
while all(a % 2 ==0 for a in ln):
    ln=[a/2 for a in ln]
    i+=1
print(i)