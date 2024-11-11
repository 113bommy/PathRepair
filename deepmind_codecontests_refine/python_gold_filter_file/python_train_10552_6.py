def main(): 
	text = input()
	lt = len(text)
	if lt<2:
		print(0)
		return

	for length in range(lt-1,0,-1):
		combinations = getCombinations(text,lt,length)
		if anyMatches(combinations):
			print(length)
			return
	print(0)

		

def anyMatches(combinations):
	c_t = len(combinations)
	for i in range(c_t-1):
		for j in range(i+1,c_t):
			if combinations[i] == combinations[j]:
				return True
	return False

def getCombinations(text,lt,length):
	temp = []
	for i in range(0,lt-length+1):
		temp.append(text[i:i+length])
	return temp


if __name__ =="__main__":
	main()