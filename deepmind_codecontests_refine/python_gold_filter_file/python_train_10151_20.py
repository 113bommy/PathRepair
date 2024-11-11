def gcd(a, b):
	if (b == 0):
		return a
	else:
		return gcd(b, a%b)

def lcm(a, b):
	return a*b//gcd(a,b)

t, w, b = (int(i) for i in input().split())
# print (gcd(w,b), lcm(w,b))

l = lcm(w,b)
g = gcd(w,b)

i = 0
# print(t - t//l*l-min(w,b)+1)
res = (t//l+1) * min(w,b)-1 + min(0, t - t//l*l - min(w,b) + 1)
g2 = gcd(res, t)
print("%d/%d" % (res//g2, t//g2))

