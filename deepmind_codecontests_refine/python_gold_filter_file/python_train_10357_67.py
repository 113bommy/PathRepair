number = str(input())
dict1 = {'1': 'one', '2': 'two', '3': 'three', '4': 'four', '5': 'five', '6': 'six', '7': 'seven', '8': 'eight', '9': 'nine', '0': 'zero'}
dict3 = {'2': 'twenty', '3': 'thirty', '4': 'forty', '5': 'fifty', '6': 'sixty', '7': 'seventy', '8': 'eighty', '9': 'ninety'}
dict2 = {'10': 'ten', '11': 'eleven', '12' : 'twelve', '13' : 'thirteen','14' : 'fourteen', '15' : 'fifteen','16' : 'sixteen','17' : 'seventeen','18' : 'eighteen', '19' : 'nineteen'}
if len(number) == 1:
	print(dict1[number])
elif number[0] == '1':
	print(dict2[number])
elif number[1] == '0':
	print(dict3[number[0]])
else:
	print(dict3[number[0]] + '-' + dict1[number[1]])