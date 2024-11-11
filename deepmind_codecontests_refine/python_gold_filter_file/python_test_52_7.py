# RANK1ZEN; 3966 PEAK NA FLEX SUPPORT; Battlenet ID -> Knuckles#11791
# region -----------------------------------------------------------------------------------------|
# MNNNNNNNNNNNNNNNNMNho///++//+oooooossssssssssssysssooyyyyyso+//++//shNNNNNNNNNNNNNM
# MNNNNNNNNNNNNNNMNy////////++++oooooooooossssssssoosssssysyyysoossss+/oshNNNNNNNNNNM
# MNNNNNNNNNNNNMNs///////+oooooo++++oooooooooooso+ossssssssssssssssssss++soymMNNNNNNM
# MNNNNNNNNNNNMd/:-//+//shNNmhsoo+++++++++ooooo++oooooooooossssssssssssso+ooosmNNNNNM
# MNNNNNNNNNNMh::://+/+ymMMMMmhsoso+++++++++o+/+ooooooooooooooooooooossso++o+++hMNNNM
# MNNNNNNNNNMy//-:/+/osmMMMMNhssyshNdssoooo++:++++++++++oooooooooooooooooo++-++/sMMNM
# MNNNNNNNNMd:/:///+/ohNMMMNhsohyyNMNNNdhhs+:++++++++++++++++++++ooooooooo/+.o+:/+NNM
# MNNNNNNNMm/:/-///++ooshmmhs+sysdMMMMNdMMd/+++++ooo++++++++++++++++++++++::-++/:/sNM
# MNNNNNNMN/://-+++++++++oo+//yosNMNMNmNMNo/o/oshNmhyoo+++++++++++++++++++/-/+++:/:sM
# MNNNNNMNo://-/+++++:/+++++//++osyhmdhMNs/o/+shMMMMmsooooyo++/+++++++++++://+++://oM
# MNNNNNMs:///:/++++//++-/+/:++++++ooooyo++o-oyNNMMmysooymmso/+shysyyysooo+/++o+/-s+M
# MNNNNMd:///+:/++++-++:`++:/++++//++++++:+-/oyhsmys+oohmyo++:sNMdmMMNNysy+-ohNs+-myM
# MNNNMN::///+-:+++:.+/``++/++++++++++++:+/`+++oo/:/++oyo+oy+odNddMMMMmyyh:-sdMh/odyN
# MNNNNo:///++-:+o/`::```++/+++++++++++//+-.o++:-:/++/+/+ymo/+ossyyhdhssy+.:ohhd/sy+M
# MMNMh-///+++--oo:`/````++-+++++++++++-o/`/+:.:/+++//+hmNo/++++++ooooooo-`/+o++/++-M
# MMMN/:///+++-.o/````-s:+/:++++++++++/++`.:.-/++++/+sdmmo/+++++++++++++: -+++++////M
# MMMh:///++++-`+:```/dN+/::++++++++++++:``.+ooo++ohNMNm++oooooooo+++++o+ :++++/-//oM
# MMd:/-/+++++-`/.``:hmm//./+++++++++o/o..:osoooymmdddmoooooooooooooo+oms.+++++////+M
# MMo// -+++++:`.`` dNddo-.:+++++++++++--/soo:.--::ymh+ssssssssssooo+sNN/++++++++/-dM
# Md/// `/+++o/```` dMddN.-:++++++++++/`/o/+:``-:-`/ooyssssssssssssoodmMo++++++++//NM
# M/:// `-+oooo.``` oMNMM+--/+++++++++/:yd-``.`-+o+hoyyoosyyyyyyys:+o+o++o//+++++/hMM
# m++:/```:oooo/````.dmNNm/-/+++++++//+dhy::ohs:/hysyosyyyyyyyyys:----:-/o/ooo++/-mMM
# s:++//```/oooo-  ``yNmdm:-/++++++////MMNmdhoys+ssssyyyyyysoysss:-.odd/o+/+oo++-+MMM
# s`:++/````:oooo. ```:hNNh-/++++++//:hNNNMMNMdsossyyyyyyss+osdM/o/:yNyoo///ooo/.MMNM
# d `-++/-```:+oo+-`````-+ds/++++++//-mMMMNNhs+syyysysyys+osdMMNyoshdh/+/o:ooo+.+MMNM
# M/` `-/+/-``.:ooo-```````s:++++++++/mNdhsoossssyyhyo/-+hmMMMMNNNNNNo//+.:oo++ oMMNM
# MMo``:..-//-.`-+oo:.`````/+++++++++:ooossyhyyyo+:-:ohNMmMMMMMNmNNNh:/:` :oo/: mMMNM
# MMMh.oMh+``.-:-.-/o+-````mh/+++++++:++++/:--:+syhmMMMMMNMMMMMMMMMo-.//``+oo:`-MMNNM
# MMMMh-omNd+````..`./+/.`hMMs+++++++/dmmmmNMMNNMMMMMMMMMMMMMMMMms:`` :/..+oo: yMNNNM
# MNNNMN/``..``````````.-.+dNy-oooooo/o+s++sNMMNmNMMmmNMMMMMMMmo-   ``-/.-oo+- yMNNNM
# MNNNNMMNdy-``````..``````-+o/+ooooo/++///:`:yMMMMMMMMMMMMds/`/++/````o--o++- MMNNNM
# MMNNMMMMMN:`........-:+oyssoo+ssssss:ooo+/+:`:mMMMMMNho/.````+ooohd+//:+ooo-/MMMMMM
# MMMMMMMMMMs.-...-.-osyyyyysdMhshhhhhossssssdh-.ss+/-.``----.sdhy+mMMMsosssy:sMMMMMM
# endregion --------------------------------------------------------------------------------------|
# region -----------------------------------------------------------------------------------------|
class Comba:
    def __init__(self, mod):
        self.fact = array.array("i", [0] * MX); self.fact[0] = 1
        self.fact_inv = array.array("i", [0] * MX)
        self.mod = mod

        for i in range(1, MX):
            self.fact[i] = (self.fact[i - 1] * i) % self.mod

        self.fact_inv[MX - 1] = pow(self.fact[MX - 1], self.mod - 2, self.mod)
        for i in range(MX - 2, -1, -1):
            self.fact_inv[i] = (self.fact_inv[i + 1] * (i + 1)) % self.mod

    def ncr(self, n, r):
        if r > n or n < 0 or r < 0: return 0
        return (self.fact[n] * self.fact_inv[r] % self.mod) * self.fact_inv[n - r] % self.mod
    
    def npr(self, n, r):
        if r > n or n < 0 or r < 0: return 0
        return self.fact[n] * self.fact_inv[n - r] % self.mod

def lcm(a, b): return a * b // gcd(a, b)

def rw_file():
    sys.stdin = open(r"", "r")
    sys.stdout = open(r"", "w")

# queries -> stdin.buffer.readline
def re(data=str): return data(sys.stdin.readline().rstrip())
def mp(data=str): return map(data, sys.stdin.readline().split())

import sys, array
from bisect import bisect_left, bisect_right, insort_left
from math import ceil, floor, log, sqrt, gcd
from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify

mod, mod9, nl, MX = 1000000007, 998244353, "\n", 200003
# endregion --------------------------------------------------------------------------------------|

def solve(tc):
    n, k = mp(int)
    ans = 0
    for m in range(43):
        if (1 << m) & k: 
            ans = (ans + n ** m) % mod
    
    print(ans)
    


    return None
 
def main():
    # rw_file()
    tests = 1; tests = re(int)
    for case in range(1, tests + 1): solve(case)

if __name__ == "__main__":
    main()
