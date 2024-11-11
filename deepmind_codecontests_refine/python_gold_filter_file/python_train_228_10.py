import sys
import math
 
#to read string
get_string = lambda: sys.stdin.readline().strip()
#to read list of integers
get_int_list = lambda: list( map(int,sys.stdin.readline().strip().split()) )
#to read non spaced string and elements are integers to list of int
get_intList_from_str = lambda: list(map(int,list(sys.stdin.readline().strip())))
#to read non spaced string and elements are character to list of character
get_charList_from_str = lambda: list(sys.stdin.readline().strip())
#get word sepetared list of character
get_char_list = lambda: sys.stdin.readline().strip().split() 
#to read integers
get_int = lambda: int(sys.stdin.readline())
#to print faster
pt = lambda x: sys.stdout.write(str(x))
#to remove all occurance of an  element in a list
def removeall_replace(element, lst):
    t = [y for y in lst if y != element]
    del lst[:]
    lst.extend(t)
 
#--------------------------------WhiteHat010--------------------------------------#
for _ in range(get_int()):
    n,m = get_int_list()
    string = get_string()
    index = get_int_list()
    d = {}
    for i in 'abcdefghijklmnopqrstuvwxyz':
        d[i] = 0
    
    arr = [0]*n
    for i in index:
        arr[i-1] += 1
    for j in range(n-2,-1,-1):
        arr[j] += arr[j+1]
    for i in range(n):
        arr[i] += 1

    for i,v in enumerate(string):
        d[v] += arr[i]
    
    lst = d.values()
    print(' '.join(map(str,lst)))