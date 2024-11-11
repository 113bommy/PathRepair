N = int(input())
count, A, B, BA = 0, 0, 0, 0
for _ in range(N):
    s = input()
    count += s.count('AB')
    B += s[0] == 'B'
    A += s[-1] == 'A'
    BA += s[0] == 'B' and s[-1] == 'A'
    #print(s, A,B,BA, 'count', count)
tmp = (A - 1) if (A == B and A == BA and BA != 0) else min(A,B)
print(count + tmp)
