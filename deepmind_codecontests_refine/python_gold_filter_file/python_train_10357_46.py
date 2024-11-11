t = [int(i) for i in input().split()][0]
a = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten']
a += ['eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen', 'twenty']
for i in range(21,100):
    if i // 10 == 2:
        cur = 'twenty'
    elif i // 10 == 3:
        cur = 'thirty'
    elif i // 10 == 4:
        cur = 'forty'
    elif i // 10 == 5:
        cur = 'fifty'
    elif i // 10 == 6:
        cur = 'sixty'
    elif i // 10 == 7:
        cur = 'seventy'
    elif i // 10 == 8:
        cur = 'eighty'
    elif i // 10 == 9:
        cur = 'ninety'
    if i % 10 == 0:
        a.append(cur)
    elif i % 10 == 1:
        a.append(cur + '-one')
    elif i % 10 == 2:
        a.append(cur + '-two')
    elif i % 10 == 3:
        a.append(cur + '-three')
    elif i % 10 == 4:
        a.append(cur + '-four')
    elif i % 10 == 5:
        a.append(cur + '-five')
    elif i % 10 == 6:
        a.append(cur + '-six')
    elif i % 10 == 7:
        a.append(cur + '-seven')
    elif i % 10 == 8:
        a.append(cur + '-eight')
    elif i % 10 == 9:
        a.append(cur + '-nine')
print (a[t])