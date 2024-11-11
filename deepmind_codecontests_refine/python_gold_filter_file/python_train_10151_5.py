def gcd(a, b):
    if b == 0 :
    	return a
    else :
    	return gcd(b, a % b)

def lca(a, b) :
	return a * b // gcd(a, b)


inp = input().split()
t = int(inp[0])
a = int(inp[1])
b = int(inp[2])

mn = min(a, b)
ans = mn - 1
#print("ans = " + str(ans))
cnt = t // lca(a, b)
ans += (cnt - 1) * (mn)
#print("ans = " + str(ans))
q = cnt * lca(a, b)

#for i in range(q, q + mn) :
	#print("yolo" + str(i))
#	if (i <= t) :
#		ans += 1
		#print("ans = " + str(ans))

add = min(mn, t - q + 1)
ans += add
g = gcd(ans, t)
ans = ans // g
t = t // g
print(str(ans) + "/" + str(t))