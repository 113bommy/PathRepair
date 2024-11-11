# -*- coding: utf-8 -*-
"""
Created on Fri Oct 15 16:55:24 2021

@author: ThanhNT
"""
# bước 1 chuyển số k về nhị phân
# bước 2 tính tổng theo công thức
max_value = 10**9 + 7
def special_number(n, k):    
    b = bin(k).replace("0b", "")        
    #print(b)
    
    i = len(b)
    result = 0
    for index in range (len(b)):
        i -=1
        result = result + int(b[index])*(n**i)
        index +=1
        if result > max_value:
            result = result % max_value
    return result


if __name__ == "__main__":

    t = int(input())
    for _ in range(0, t):
        n, k = map(int,input().split(" "))
        print (special_number(n, k))