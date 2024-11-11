import glob



# 問題ごとのディレクトリのトップからの相対パス
REL_PATH = 'ABC\\AGC\\C'

# テスト用ファイル置き場のトップ
TOP_PATH = 'C:\\AtCoder'


class Common:
    problem = []
    index = 0

    def __init__(self, rel_path):
        self.rel_path = rel_path

    def initialize(self, path):
        file = open(path)
        self.problem = file.readlines()
        self.index = 0
        return

    def input_data(self):
        try:
            IS_TEST
            self.index += 1
            return self.problem[self.index - 1]

        except NameError:
            return input()

    def resolve(self):
        pass

    def exec_resolve(self):
        try:
            IS_TEST
            for path in glob.glob(TOP_PATH + '\\' + self.rel_path + '/*.txt'):
                print("Test: " + path)
                self.initialize(path)
                self.resolve()
                print("\n\n")
        except NameError:
            self.resolve()


class C(Common):

    def resolve(self):

        ring_len = int(self.input_data())
        first_ring = [int(i) for i in self.input_data().split()]
        now_ring = [int(i) for i in self.input_data().split()]

        count = 0
        result = True
        loop = True


        while loop:

            result = True
            loop = False
            i = 0

            while i < ring_len:
                if first_ring[i] == now_ring[i]:
                    i += 1
                    continue

                result = False

                if first_ring[i] > now_ring[i]:
                    break
                if i != 0:
                    prv = i - 1
                else:
                    prv = ring_len - 1

                if i != ring_len - 1:
                    nxt = i + 1
                else:
                    nxt = 0

                if now_ring[i] > now_ring[prv] + now_ring[nxt]:
                    loop = True
                    tmp = int((now_ring[i] - first_ring[i]) / (now_ring[prv] + now_ring[nxt]))
                    if tmp == 0:
                        loop = False
                        break
                    loop = True
                    now_ring[i] -= (now_ring[prv] + now_ring[nxt])*tmp
                    count += tmp
                    i = i - 2
                    if i < -1 :
                        i += ring_len

                i += 1

            if result:
                loop = False

        if result:
            print(str(count))
        else:
            print("-1")


solver = C(REL_PATH)
solver.exec_resolve()