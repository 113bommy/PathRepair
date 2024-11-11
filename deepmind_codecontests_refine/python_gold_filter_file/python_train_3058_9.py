temp = str(input());
a, b, n = temp.split(' ');

n = int(n);
b = int(b);

def number_of_digits(n):
    n = int(n);
    s = 1;
    n /= 10;

    while n > 0:
        s += 1;
        n /= 10;

    return s;

#Find a correct digit to add
#so, it becomes divisible by b
flag = False;
for i in range(0, 10):
    if (int(a)*10 + i)%b == 0:
        a += str(i);
        flag = True;
        n -= 1;
        break;

#print(a);

if flag:
    a = int(int(a)*pow(10, n));
else:
    a = -1;

print(a);