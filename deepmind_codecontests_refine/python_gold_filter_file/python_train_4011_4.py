s, x = map(int, input().split())
print(((s-x)&(x+x+1)==0 and x <= s) * (2 ** bin(x).count('1') - 2 * (s == x)))
