#import sys
#
#count=0
#
#for line in sys.stdin:
#    count +=1
#    if count > 1:
#        if len(line.strip('\n')) <= 10:
#            print(line.strip('\n'))
#        if len(line.strip('\n')) > 10:
#            print(line[0] + str((len(line.strip('\n')))-2) +  line[-2])

#vowels =  ["A", "a", "O", "o", "Y", "y", "E", "e", "U", "u", "I", "i"]
#output = ""
#
#string = input()
#for char in range(len(string)):
#    if string[char] in vowels:
#        pass
#    else:
#        output += "."
#        output += string[char].lower()
#print(output)


#import sys
#
#count=0
#
#for line in sys.stdin:
#    count +=1
#    if count == 2:
#        a = line.strip('\n').split()
#        a.sort()
#        print(a)
#    if count == 3:
#        b = line.strip('\n').split()
#        b.sort()
#        print(b)
#    if count == 4:
#        c = line.strip('\n').split()
#        c.sort()
#        print(c)
#
#count=0
#
#def removeFirstDouble(a, b):
#    if a[0] == b[0]:
#        a.remove(a[0])
#        b.remove(b[0])
#
#removeFirstDouble(a,b)
#print(a)



#import sys
#
#count=0
#
#for line in sys.stdin:
#    count +=1
#    if count == 1:
#        a = line.strip('\n')
#    if count == 2:
#        b = line.strip('\n')
#
#if a == b[::-1]:
#    print("YES")
#else:
#    print("NO")


#class Stack:
#     def __init__(self):
#         self.items = []
#
#     def isEmpty(self):
#         return self.items == []
#
#     def push(self, item):
#         self.items.append(item)
#
#     def pop(self):
#         return self.items.pop()
#
#     def peek(self):
#         return self.items[len(self.items)-1]
#
#     def size(self):
#         return len(self.items)
#
#s=Stack()
#numbers =  ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]
#operations = ["+", "*"]
#
#string = input()
#for char in range(len(string)):
#    if string[char] in numbers:
#        print(string[char])
#        s.push(string[char])
#    else:
#        a = s.pop()
#        b = s.pop()
#        print(eval(a + string[char] + b))


#import sys
#
#string = input()
#result = (string.find("0"*7) > -1) or (string.find("1"*7) > -1)
#
#if result:
#    print("YES")
#else:
#    print("NO")


import sys

cachedInput = sys.stdin
count=0
totalNumberInLecture = 0
numberOfWordsInEachLanguage = 0
dictionary = {}
result = []

def returnShortest(list):
    if len(list[0]) <= len(list[1]):
        return list[0]
    else:
        return list[1]

line = input()
a = line.strip('\n').split()
totalNumberInLecture = int(a[0])
numberOfWordsInEachLanguage = int(a[1])
#print(totalNumberInLecture)
#print(numberOfWordsInEachLanguage)


for line in cachedInput:
    count +=1
    if count <= numberOfWordsInEachLanguage:
        currentLine = line.strip('\n').split()
        dictionary[currentLine[0]] = returnShortest(currentLine)
#        print(dictionary)
    else:
        lecture = line.strip('\n').split()



#print(dictionary)
for word in lecture:
    result.append(dictionary[word])

print(" ".join(result))







