N = int(input())
A=list(map(int, input().split()))

red = 0
rate = []

for a in A:
    if(a>=3200):
        red += 1
    else:
        rate.append(min(a//400,7))

cnt = len(set(rate))

print(max(1,cnt),cnt+red)