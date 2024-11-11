def gcd (a, b):
	if b == 0:
	    return a;
	else:
		return gcd (b, a % b);

def lcm (a, b):
	return a // gcd (a, b) * b;

t, w, b = input().split()
t = int(t)
w = int(w)
b = int(b)
ans = (t // lcm(w, b)) * min(w, b) - 1 + min(t - t // lcm(w, b) * lcm(w, b) + 1, min(w, b));
print(ans // gcd(ans, t), end="")
print("/", end="")
print(t // gcd(ans, t))