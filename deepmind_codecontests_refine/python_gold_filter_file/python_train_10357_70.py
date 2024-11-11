n = int(input())
small = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
big = ['', 'ten', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
middle = ['', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
if n == 0:
    print('zero')
elif 11 <= n <= 19:
    print(middle[n - 10])
else:
    print(big[n // 10], end='')
    if n % 10 != 0 and n >= 10:
        print('-', end='')
    print(small[n % 10])