t = int(input())
for i in range(0,t):
	candles=int(input())
	if candles%2==0:
		print(int(candles/2-1))
	else:
		print(candles//2)