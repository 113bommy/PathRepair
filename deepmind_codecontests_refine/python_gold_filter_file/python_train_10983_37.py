#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(0);
#define IO STD std_enable = 1; cin.tie(0);
#define STD /*
from sys import (
stdin, stdout, exit as sys_ret)
"""****************************

       Interactive Tasks:

          / Python: /       """
f_input, f_print, f_flush = (
        stdin.readline,
        stdout.write,
        stdout.flush)

"""        / C++ /
       #import <cstdio>
       fflush(stdout);
             or
       #import <iostream>
       cout << endl;

   —————————————————————————
    Don't raise your voice,
    improve your argument.
   —————————————————————————

   cat /dev/ass > /dev/head
            Ctrl+C
   cat /knowledge > /dev/head

                © Jakov Gellert
                        frvr.ru

****************************"""
# */ using namespace std; int
#define boost_stream(); IO SYNC

word = f_input().replace('\n', '')
upper_cases = sum([1 if i.isupper() else 0 for i in word])
f_print(word.upper() if upper_cases > len(word) // 2 else word.lower())