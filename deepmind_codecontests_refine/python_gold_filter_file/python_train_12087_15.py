# 1030a
n = int(input())
easy=hard=0
m = list(int(i) for i in input().strip().split())
if n != len(m):
    print(f'InputError: expected {n} input(s) recieved {len(m)}')
for i in range(n):
    if m[i]==0:
        easy+=1
    elif m[i]==1:
        hard+=1
if easy==n:
    print("easy")
else:
    print("hard")

