"""
B. Phone Numbers
time limit per test: 2 seconds.

Winters are just damn freezing cold in Nvodsk! That's why a group of n
friends prefers to take a taxi, order a pizza and call girls.
The phone numbers in the city consist of three pairs of digits (for example,
12-34-56). Each friend has a phonebook of size s i (that's the number of phone
numbers). We know that taxi numbers consist of six identical digits (for
example, 22-22-22), the numbers of pizza deliveries should necessarily be
decreasing sequences of six different digits (for example, 98-73-21), all
other numbers are the girls' numbers.

You are given your friends' phone books. Calculate which friend is best to go
to when you are interested in each of those things (who has maximal number of
phone numbers of each type).

If the phone book of one person contains some number two times, you should
count it twice. That is, each number should be taken into consideration the
number of times it occurs in the phone book.

2 Fedorov
22-22-22
98-76-54
3 Melnikov
75-19-09
23-45-67
99-99-98
7 Rogulenko
22-22-22
11-11-11
33-33-33
44-44-44
55-55-55
66-66-66
95-43-21
3 Kaluzhin
11-11-11
99-99-99
98-65-32
"""
import re
import pdb

from sys import stdin, stdout

def solve_challenge():
    #pdb.set_trace()
    inp = get_input()
    books = parse_input(inp)
    (taxis_top, pizzas_top, girls_top) = get_solution(books)
    print_solution(taxis_top, pizzas_top, girls_top)


def get_input_file():
    import sys
    f = open("demo.txt", "r")
    var = f.read()
    #print(var)
    return var


def get_input():
    import sys
    var = sys.stdin.read()
    return var


def parse_input(inp):
    books = list()
    lines = inp.splitlines()
    #print(lines)
    #num_friends = lines[0]
    is_name_line = True

    for line in lines[1:]:
        if is_name_line:
            arr = line.split(' ')
            (number, friend) = (int(arr[0]), arr[1])
            phonebook = list()
        else:
            phone = line.replace('-','')
            phonebook.append(phone)
            number -= 1

        if number == 0:
            is_name_line = True
            friend_tuple = (friend, phonebook)
            books.append(friend_tuple)
        else:
            is_name_line = False

    return books


def get_solution(books):
    taxis_max = 0
    pizzas_max = 0
    girls_max = 0
    taxis_top = list()
    pizzas_top = list()
    girls_top = list()

    for book in books:
        taxis_count = 0
        pizzas_count = 0
        girls_count = 0
        (friend, phonebook) = book

        for number in phonebook:
            if is_taxi_number(number):
                taxis_count += 1
            elif is_pizza_number(number):
                pizzas_count += 1
            else:
                girls_count += 1

        (taxis_max, taxis_top) = get_max(taxis_count, taxis_max, taxis_top, friend)
        (pizzas_max, pizzas_top) = get_max(pizzas_count, pizzas_max, pizzas_top, friend)
        (girls_max, girls_top) = get_max(girls_count, girls_max, girls_top, friend)

    return (taxis_top, pizzas_top, girls_top)


def get_max(count, maximum, top, friend):
    if count > maximum:
        maximum = count
        top = [friend]
    elif count == maximum:
        top.append(friend)

    return (maximum, top)


def is_pizza_number(num):
    for i in range(1, 6):
        if int(num[i]) >= int(num[i-1]):
            return False
    return True


def is_taxi_number(num):
    return bool(re.match(r"(\w)\1{5,}", num))


def print_solution(taxis_top, pizzas_top, girls_top):
    taxis = "If you want to call a taxi, you should call: %s." % (
        ', '.join(taxis_top))
    pizzas = "If you want to order a pizza, you should call: %s." % (
        ', '.join(pizzas_top))
    girls = "If you want to go to a cafe with a wonderful girl, you should call: %s." % (
        ', '.join(girls_top))
    print(taxis)
    print(pizzas)
    print(girls)


def main():
    solve_challenge()

if __name__ == "__main__":
   main()
