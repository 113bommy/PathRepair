def divi_64(string):
    try:
        location_1 = string.index('1')
    except:
        return 'no'
    length = len(string)
    new_str = string[location_1:length]
    num_0 = new_str.count('0')
    if(num_0>=6):
        return 'yes'
    else:
        return 'no'
str = input()
ans = divi_64(str)
print(ans)