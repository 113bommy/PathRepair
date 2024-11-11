v = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
v2 = ['', '', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']

n = int(input())
if (n < len(v)):
	print(v[n])
else:
	if (n % 10 != 0):
		print(v2[n//10] + '-' + v[n%10]);
	else:
		print(v2[n//10])
