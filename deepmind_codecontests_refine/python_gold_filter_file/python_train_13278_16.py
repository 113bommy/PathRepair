n = int(input())
a = 'that I hate that I love '
b = 'that I love that I hate '
if n == 1:
    s = 'I hate it'
elif n == 2:
    s = 'I hate that I love it'
elif n % 2 == 1 and n > 2:
    s = 'I hate ' + b * (n//2) + 'it'
else:
    s = 'I hate that I love ' + a * (n//2 - 1) + 'it'
print(s)
