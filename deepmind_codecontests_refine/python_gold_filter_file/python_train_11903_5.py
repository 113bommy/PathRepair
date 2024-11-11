k = int(input())
string = input().strip()
# string = "".join([str(1) for a in range(0, 10 ** 6)])
dp = [0 for a in range(0, len(string))]

if string[0] == "0":
	dp[0] = 0
else:
	dp[0] = 1

for a in range(1, len(string)):
	if string[a] ==  "0":
		dp[a] = dp[a - 1]
	else:
		dp[a] = dp[a - 1] + 1

hashmap = [0 for a in range(0, max(dp) + 1)]

for a in range(0, len(dp)):
	hashmap[dp[a]] += 1

# print(dp)

# print(hashmap)

try:
	if k == 0:
		# ans = max(0, hashmap[0])

		# change = len(dp) - len(hashmap)s
		# ans = hashmap[0] + change
		ans = hashmap[k]
		for d in range(k, len(hashmap)):
			ans += ((hashmap[d] * (hashmap[d - k]-1))//2)
	else:
		ans = hashmap[k]
		for d in range(k, len(hashmap)):
			ans += (hashmap[d] * hashmap[d - k])

	print(ans)
except IndexError:
	print(0)