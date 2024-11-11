n = int(input())
d = {1:['ten',
        'eleven',
        'twelve',
        'thirteen',
        'fourteen',
        'fifteen',
        'sixteen',
        'seventeen',
        'eighteen',
        'nineteen',],
     2:'twenty',
     3:'thirty',
     4:'forty',
     5:'fifty',
     6:'sixty',
     7:'seventy',
     8:'eighty',
     9:'ninety'}
f = ['zero',
     'one',
     'two',
     'three',
     'four',
     'five',
     'six',
     'seven',
     'eight',
     'nine']
if n // 10 == 0:
    print(f[n])
elif n // 10 == 1:
    print(d[1][n%10])
else:
    s = d[n//10];
    if n%10 != 0:
        s = s +'-'+ f[n%10]
    print(s)