n =  int(input())
ss = [int(i) for i in input().split()]
Maximum = max(ss)
Minimum = min(ss)
a = ss.index(Maximum)
b = ss[::-1].index(Minimum)
if a + b + 1 >= n:
    final = a + b -1
else:
    final = a + b

print(final)