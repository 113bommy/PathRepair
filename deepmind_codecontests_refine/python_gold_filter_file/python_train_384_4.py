n = int(input())
p = [i for i in map(int, input().split())]
ans1 = 0
ans2 = 0
p.sort()
for i in range(0, int(n/2)):
    ans1 += abs(p[i] - (i * 2 + 1));
    ans2 += abs(p[i] - (i * 2 + 2));
    
print(min(ans1, ans2))