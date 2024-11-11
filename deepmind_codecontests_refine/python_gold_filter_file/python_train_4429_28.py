# Problem URL: https://codeforces.com/problemset/problem/658/A

n,c = list(map(int,input().split()))

p = list(map(int,input().split()))
t = list(map(int,input().split()))

limak_score = radewoosh_score = 0

time = 0
for i in range(n):
    time += t[i]
    limak_score += max(0,p[i]-(c*time))

time = 0
for j in range(n-1,-1,-1):
    time+=t[j]
    radewoosh_score += max(0,p[j] - (c*time))

if limak_score < radewoosh_score:
    print("Radewoosh")
elif limak_score > radewoosh_score:
    print("Limak")
else:
    print("Tie")