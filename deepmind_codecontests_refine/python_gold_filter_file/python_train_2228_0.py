n, m = input().split()
n = int(n)
m = int(m)
puzzles=input().split()
for i in range (m):
    puzzles[i]=int(puzzles[i])
ordered=[]
for i in range (m):
    ordered.append(max(puzzles))
    puzzles.remove(max(puzzles))
minimum=0
for j in range (m-n+1):
    count=ordered[j]-ordered[j+n-1]
    if j==0:
        minimum=count
    elif count<minimum:
        minimum=count
print(minimum)
