class CustomException(Exception): pass

def main():
	n = int(input())
	x = n//7
	y = n//4
	try:
		for i in reversed(range(x+1)):
			for j in range(y+1):
				if (7*i+4*j==n):
					print('4'*j, '7'*i, sep='')
					raise CustomException
				elif (7*i+4*j>n):
					break
	except CustomException as err:
		pass
	else:
		print('-1')


if __name__ == '__main__':
	main()

