

def bin_search(number):
    left_bound = 0
    right_bound = number
    middle = right_bound + left_bound / 2
    while (abs(number - middle * (number - middle)) >= 0.000000001):
        middle = (right_bound + left_bound) / 2
        if middle * (number - middle) > number:
            right_bound = middle
        else:
            left_bound = middle
    return left_bound, number - left_bound

amount = int(input())
#print(bin_search(1))
for i in range(amount):
    number = int(input())
    if number < 4 and number > 0:
        print('N')
    else:
        first, second = bin_search(number)
        #print( abs(first + second - first * second), abs(first + second - number))
        if abs(first + second - first * second) <= 10e-6 and abs(first + second - number) <= 10e-6:
            print('Y', first, second)
        else:
            print('difference')
        #print("Y", first, second)
    
"""a + b = d
a * b = d
=> a = d - b
=> (d - b) * b = d
=> db - b^2 = d
=> -b^2 - db - d = 0
=> b^2 + db + d = 0
D = d^2 - 4d
d(d - 4) < 0 => d (0;4) doesn't have any solutions"""