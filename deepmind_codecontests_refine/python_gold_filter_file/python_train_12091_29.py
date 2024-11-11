n, m, k = map(int, input().split())
l = list(map(int, input().split()))
l.sort()
a = m//(k+1)
x = m%(k+1)
a1 = a*k*l[-1] + l[-2]*a + x*l[-1]
print(a1)