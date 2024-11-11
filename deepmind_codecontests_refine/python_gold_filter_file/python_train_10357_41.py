n = int(input())

unit = n%10
dec = n//10

dec_s = ""
unit_s = ""


_dec = {2: "twenty", 3: "thirty", 4:"forty", 5: "fifty", 6: "sixty", 7: "seventy", 8: "eighty", 9: "ninety"}
_unit = {0:"zero",1: "one", 2: "two", 3: "three", 4: "four", 5:"five", 6: "six", 7: "seven", 8: "eight", 9: "nine"}

if n<10:
	print(_unit[n])

if dec == 1:
	_decenas = {10:"ten",11:"eleven",12:"twelve",13:"thirteen",14:"fourteen",15:"fifteen",16:"sixteen",17:"seventeen",18:"eighteen",19:"nineteen"}
	print(_decenas[n])

if dec >= 2:
	if unit > 0:
		print(_dec[dec]+"-"+_unit[unit])
	else:
		print(_dec[dec])

