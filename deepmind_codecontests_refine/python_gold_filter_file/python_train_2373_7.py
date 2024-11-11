a = int(input())
if a%100<=((a-(a%100))/100)*5:
    print(1)
else:
	print(0)