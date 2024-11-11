n = input()
l = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
m = ['ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
o = ['twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']

if int(n) > 19 and n[1] != '0':
    print(o[int(n[0]) - 2] + '-' + l[int(n[1])])
elif int(n) > 19 and n[1] == '0':
    print(o[int(n[0]) - 2])
elif 19 >= int(n) > 9:
    print(m[int(n) - 10])
elif int(n) <= 9:
    print(l[int(n)])
