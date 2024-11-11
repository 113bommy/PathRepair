import math
from sys import stdin
from math import ceil
import sys
from math import sqrt

if __name__ == '__main__':
    number = int(input())
    primNumb = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    vector = []
    vector.append([])
    for i in range(1, number + 1):
        vector.append([])
        for j in range(10):
            vector[i].append(0)
            if i == 1:
                vector[i][j] = 1
            else:
                vector[i][j] = 2 ** (i - 1)
                if j == 0:
                    continue
                #if j != 0:
                for l in range(1, i):
                    if i % (l + 1) == 0:
                            div = vector[i//(l + 1)][j - 1] * (primNumb[j]**l)
                            vector[i][j] = min(vector[i][j], div)
                            # if vector[i][j] > div:
                                # vector[i][j] = div
                vector[i][j] = min(vector[i][j], vector[i][j - 1])
                # if vector[i][j] > vector[i][j - 1]:
                    # vector[i][j] = vector[i][j - 1]
    print(vector[number][9])

