n, m = map(int,input().split())
dots = []
count = 0
line = [True]*m
for i in range(n):
    l,r = map(int,input().split())
    for j in range(l-1,r):
        line[j] = False
    if l == r:
        line[l-1]= False
for i in range(m):
    if line[i]:
        count+=1   
        dots.append(i+1)
print(count)
for i in range(len(dots)):
    print(dots[i],end = " ")