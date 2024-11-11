x = int(input())
sum = 0
pow = 0
while 10**(pow+1) <= x:
	pow += 1
#print("Pow: " + str(pow))
sum = (10**pow)*(pow)
#print("Raw 10s Digits: " + str(sum))
sum += (x - 10**pow + 1)*(pow+1)
#print("Added LeftOvers: " + str(sum))
for i in range(0, pow):
	sum -= 10**i
print(sum)