# _1294c
##########

def productOfThreeNumbers(n, answer=(1, )):
	lengthOfAnswer = len(answer)
	if lengthOfAnswer == 3:
		if n > answer[-1]:
		    return f'YES\n{answer[1]} {answer[2]} {int(n)}'
		return 'NO'
	
	for i in range(answer[-1]+1, int(n**(1/(4-lengthOfAnswer)))+1):
		if not n%i:
			return productOfThreeNumbers(n/i, answer+(i, ))
	
	return 'NO'


nTestCases = int(input())
testCases = [int(input()) for x in range(nTestCases)]
[print(productOfThreeNumbers(testCase)) for testCase in testCases]
