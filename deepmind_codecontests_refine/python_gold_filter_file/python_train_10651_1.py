from collections import Counter
from pprint import pprint
n = int(input().strip())
t = n
books = []
while t > 0:
    friend = input().strip().split()
    phonebook = []
    friend[0] = int(friend[0])
    si = friend[0]
    while si > 0:
        number = input().strip()
        phno = []
        for val in number:
            if val != '-':
                phno.append(int(val))
        phonebook.append(phno)
        si -= 1
    books.append((friend[1], phonebook))
    t -= 1

number_categories = {}
max_pizza = 0
max_girls = 0
max_taxi = 0

for book in books:
    friend = book[0]
    number_categories[friend] = Counter()
    for contact in book[1]:
        digit_dict = Counter(contact)
        if len(digit_dict) == 1:
            number_categories[friend]['taxi'] += 1
        elif len(digit_dict) != len(contact):
            number_categories[friend]['girls'] += 1
        else:
            flag = False
            for i in range(1, len(contact)):
                if contact[i] > contact[i-1]:
                    flag = True
                    break
            if flag == False:
                number_categories[friend]['pizza'] += 1
            else:
                number_categories[friend]['girls'] += 1
    
    max_pizza = max(max_pizza, number_categories[friend]['pizza'])
    max_taxi = max(max_taxi, number_categories[friend]['taxi'])
    max_girls = max(max_girls, number_categories[friend]['girls'])

max_taxi_list = [book[0] for book in books if number_categories[book[0]]['taxi'] == max_taxi]
max_pizza_list = [book[0] for book in books if number_categories[book[0]]['pizza'] == max_pizza]
max_girls_list = [book[0] for book in books if number_categories[book[0]]['girls'] == max_girls]

print('If you want to call a taxi, you should call:', ", ".join(max_taxi_list), end='.\n')
print('If you want to order a pizza, you should call:', ", ".join(max_pizza_list), end='.\n')   
print('If you want to go to a cafe with a wonderful girl, you should call:', ", ".join(max_girls_list), end='.\n') 
