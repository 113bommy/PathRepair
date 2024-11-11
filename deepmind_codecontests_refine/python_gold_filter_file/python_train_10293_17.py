N = int(input())
As = list(map(int,input().split()))
anss=[]
for i in range(-101,101):
    anss.append(sum([abs(i-a)**2 for a in As]))
print(min(anss))