n, m, *d = open(0).read().split()
n, m = int(n), int(m)
r = range(n - m + 1)
print(["No","Yes"][any(d[n:] == [t[j:j+m] for t in d[i:i+m]] for i in r for j in r)])