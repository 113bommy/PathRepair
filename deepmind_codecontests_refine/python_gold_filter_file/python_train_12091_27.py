nmk = input().strip().split(" ")
n = int(nmk[0])
m = int(nmk[1])
k = int(nmk[2])

emojis = input().strip().split(" ")
emojis = [int(x) for x in emojis]

max1 = max(emojis)
emojis.remove(max1)
max2 = max(emojis)

seq = max1 * k + max2
happ = m // (k + 1) * seq + m % (k + 1) * max1

print(happ)
