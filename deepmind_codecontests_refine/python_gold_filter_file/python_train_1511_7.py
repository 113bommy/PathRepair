#INTNOF
n = input()
weights = input()
bits = [0 for i in range(1001015)]
#print sorted(weights)
for w in weights.split():
	bits[int(w)]+=1
ans = 0
#print bits[0:n]
for i in range(1001010):
	bits[i+1] += bits[i]>>1
	ans+= (bits[i]&1)
print(ans)
#print 1000000
#print ' '.join(map(str, range(1000000)))