from fractions import Fraction


n, m = map(int, input().split())
xs, ds = zip(*(list(map(int, input().split())) for i in range(m)))
negative_ds = 0
positive_ds = 0
for d in ds:
    if d > 0:
        positive_ds += d
    else:
        negative_ds += d
max_distations = (n-1)*n//2
min_distations = (1+n//2)*(n//2)-(n//2 if n%2 == 0 else 0)
result = float(Fraction(n*sum(xs)+positive_ds*max_distations+negative_ds*min_distations, n))
print(result)
