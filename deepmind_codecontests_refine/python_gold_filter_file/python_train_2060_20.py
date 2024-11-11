n = list(reversed([0]+list(map(int, input()))))
ans = 0
for i in range(len(n)):
    if n[i] < 5 or (n[i]==5 and n[i+1]<5):
        ans += n[i]
    else:
        ans += 10 - n[i]
        n[i+1] += 1
print(ans)