s = input()
K = int(input())
sub = {s}
for d in range(1,6):
    for i in range(len(s)-d+1):
        sub |= {s[i:i+d]}
print(sorted(sub)[K-1])