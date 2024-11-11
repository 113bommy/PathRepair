n=[input() for _ in range(int(input()))]
if len(set(n))!=len(n): print('No');exit()
print('NYoe s'[all([1 if n[i-1][-1]==n[i][0] else 0 for i in range(1,len(n))])::2])